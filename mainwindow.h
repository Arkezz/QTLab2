#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <algorithm>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();

private slots:
	void on_normalSearchButton_clicked();

	void on_binarySearchButton_clicked();

	void on_generateDataButton_clicked();

	void on_mergeSortButton_clicked();

	void on_stlSortButton_clicked();

	void on_findButton_clicked();

private:
	Ui::MainWindow* ui;
	//Array that is going to be sorted
	int* array;
	//Size of the array
	int size;
	//Number that is going to be searched
	int number;
	//merge function
	void merge(int* array, int left, int middle, int right);
	//mergeSort function
	void mergeSort(int* array, int left, int right);
};
#endif // MAINWINDOW_H
