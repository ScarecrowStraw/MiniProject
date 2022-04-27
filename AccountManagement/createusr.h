#ifndef CREATEUSR_H
#define CREATEUSR_H


#include <QWidget>
#include <QString>
namespace Ui {
class Createusr;
}
class Createusr : public QWidget
{
Q_OBJECT
public:
explicit Createusr(const QString& name, QWidget *parent = 0);
~Createusr();
private:
Ui::Createusr *ui;
};
#endif //CREATEUSR_H
