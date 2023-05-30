#include <bookkeeper_thing/version.hh>
//
#include <QtCore/QString>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QWidget>
//

int main(int argc, char** argv)
{
  QApplication app(argc, argv);

  QWidget* widget = new QWidget;
  QHBoxLayout* layout = new QHBoxLayout;
  widget->setLayout(layout);
  layout->addWidget(new QLabel(gccore::bookkeeper_thing::kName));
  widget->show();

  int32_t const result = app.exec();
  std::exit(result);
}
