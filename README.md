# SimpleCrypt

A idéia do SimpleCrypt é fornecer alguns recursos criptográficos básicos para criptografia simples. Somente a criptografia simétrica é suportada (= mesma chave para criptografia e descriptografia necessária) e não há API para transmitir e receber dados como você costuma ver com os códigos mais avançados. Se você precisar de criptografia mais forte, códigos de streaming ou chaves assimétricas, consulte o QCA.

A classe SimpleCrypt usa uma chave de 64 bits na forma de um quint64. Se você usar uma compilação de chave fixa em seu programa, poderá fazer algo assim para inicializar seu objeto SimpleCrypt:

SimpleCrypt crypto(Q_UINT64_C(0x0c2ad4a4acb9f023)); //algum número aleatório


Mas você também pode usar o método SimpleCrypt::setKey() para definir a chave.

SimpleCrypt crypto();
crypto.setKey(0x0c2ad4a4acb9f023);


# Métodos de criptografia
 QString encryptToString(const QString& plaintext);
 QString encryptToString(QByteArray plaintext);
 QByteArray encryptToByteArray(const QString& plaintext);
 QByteArray encryptToByteArray(QByteArray plaintext);
 
 # Métodos de descriptografia
  QString decryptToString(const QString& plaintext);
  QString decryptToString(QByteArray plaintext);
  QByteArray decryptToByteArray(const QString& plaintext);
  QByteArray decryptToByteArray(QByteArray plaintext);
  
  # Use com QStrings
  SimpleCrypt crypto(Q_UINT64_C(0x0c2ad4a4acb9f023)); //some random number
  QString testString("Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
 
  //Encryption
  QString result = crypto.encryptToString(testString);

  //Decryption
  QString decrypted = crypto.decryptToString(result);
  qDebug() << testString << endl << result << endl << decrypted;
