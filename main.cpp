#include <QCoreApplication>
#include <QDebug>
#include <QBuffer>
#include "simplecrypt.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    quint64 saultKey = 0x54455f66552a846f;
    quint64 saultKey2 = 0x54455f66552a8931;

    SimpleCrypt crypto(saultKey);

    SimpleCrypt decrypto(saultKey2);

    //crypto.setCompressionMode(SimpleCrypt::CompressionAlways);
    //crypto.setIntegrityProtectionMode(SimpleCrypt::ProtectionHash);

    QString passNormal = "12345";

    qDebug() << "Password Normal: " << passNormal;

    QString passEncrypt1 = crypto.encryptToString(passNormal);
    qDebug() << "Password Encrypt: " << passEncrypt1;
    QString passEncrypt2 = crypto.encryptToString(passNormal);
    qDebug() << "Password Encrypt: " << passEncrypt2;

     QString passDecrypt1 = crypto.decryptToString(passEncrypt1);
     QString passDecrypt2 = crypto.decryptToString(passEncrypt2);

     qDebug() << "Password Decrypt: " << passDecrypt1;
     qDebug() << "Password Decrypt: " << passDecrypt2;

     qDebug() << "Password Encrypt of Decrypt: " << crypto.encryptToString(passDecrypt1);
     qDebug() << "Password Encrypt of Normal: " << crypto.encryptToString(passNormal);

     qDebug() << "Password sem saltkey: " << decrypto.decryptToString(passEncrypt1);

    return a.exec();
}
