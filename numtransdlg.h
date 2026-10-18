#ifndef NUMTRANSDLG_H
#define NUMTRANSDLG_H

#include <QDialog>
class QLineEdit;
class NumTransdlg : public QDialog
{
    Q_OBJECT

public:
    explicit NumTransdlg(QWidget *parent = nullptr);
    ~NumTransdlg() override;

private:
    QLineEdit* decEdit;
    QLineEdit* hexEdit;
    QLineEdit* binEdit;

private slots:
    void decChanged(const QString&);
    void hexChanged(const QString&);
    void binChanged(const QString&);
};
#endif // NUMTRANSDLG_H
