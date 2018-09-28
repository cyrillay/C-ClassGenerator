#ifndef FENCODEGENERE_H
#define FENCODEGENERE_H

#include "fenprincipale.h"


class fencodegenere : public QWidget
{
    Q_OBJECT

public:
    fencodegenere(QString* code);

public slots:
    void sauvegarder();


private:
    QVBoxLayout* m_layout;
    QPushButton* m_bout1;
    QPushButton* m_bout2;
    QTextEdit* m_texte;

};



#endif // FENCODEGENERE_H
