#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QFont>
#include <QIcon>
#include <QWidget>
#include <QTextCodec>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include <QLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QGroupBox>
#include <QRadioButton>
#include <QCheckBox>
#include <QDateTimeEdit>
#include <QTextEdit>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QInputDialog>
#include <QFileDialog>
//#include <QMenu>
#include <QMenuBar>
#include <QMainWindow>
#include "fencodegenere.h"


class FenPrincipale : public QMainWindow
{
    Q_OBJECT

public:

    FenPrincipale();

private slots:
    void popup();

private:

    QVBoxLayout* m_layout_principal;

    QGroupBox* m_formulaire;
        QFormLayout* m_layout_formulaire;
        QLineEdit* m_champ1;
        QLineEdit* m_champ2;

    QGroupBox* m_cases;
        QVBoxLayout* m_layout_cases;
        QCheckBox* m_check1;
        QCheckBox* m_check2;
        QCheckBox* m_check3;

    QGroupBox* m_commentaires;
        QFormLayout* m_layout_commentaires;
        QCheckBox* m_check4;
        QLineEdit* m_com1;
        QDateTimeEdit *m_date;
        QTextEdit* m_texte;
        QString m_code;

    QPushButton* m_bouton1;
    QPushButton* m_bouton2;




};

#endif // FENPRINCIPALE_H
