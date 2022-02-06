#include <cache_manager.h>
#include <quazip.h>
#include <quazipfile.h>

QString cache_manager::get_cached_app_path(QString app_name) {
    QDir cur_app_dir = QDir(APPS_DIR.filePath(app_name));
    if (!cur_app_dir.exists()) {
        return QString();
    }
    QFile qml_file(cur_app_dir.filePath("app.qml"));
    if (!qml_file.exists()) {
        qDebug() << "Can not find app.qml in directory " << cur_app_dir << '\n';
        return QString();
    }
    return qml_file.fileName();
}

QString cache_manager::save_zip_to_cache(QFile archive_file) {
    QFileInfo archiveFileInfo(archive_file.fileName());
    QString app_name = archiveFileInfo.baseName();
    QDir app_dir(APPS_DIR.filePath(app_name));

    // remove older version
    if (app_dir.exists()) {
        app_dir.removeRecursively();
    }

    return app_dir.path();
}

void cache_manager::unzip_to_folder(QFile archive_file, const QDir &dest_dir) {
    if (!archive_file.exists()) {
        qDebug() << "Can not unpack the archive: " << archive_file.fileName() << " does not exists\n";
        return;
    }
    dest_dir.mkpath(".");

    QuaZip archive(archive_file.fileName());
    archive.open(QuaZip::mdUnzip);
    archive.goToFirstFile();
    for (const QString &filename: archive.getFileNameList()) {
        QFile current_dest(dest_dir.filePath(filename));
        QuaZipFile current_archived_file(&archive);
        current_dest.open(QIODevice::WriteOnly);
        while (!current_archived_file.atEnd()) {
            QByteArray buffer = current_archived_file.read(BUFFER_SIZE);
            current_dest.write(buffer);
        }
        current_dest.close();
        archive.goToNextFile();
    }
    qDebug() << "Unpacked " << archive_file.fileName() << " to " << dest_dir.path() << '\n';
    archive.close();
}
