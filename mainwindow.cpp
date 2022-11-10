#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}
void MainWindow::merge(int* array, int left, int middle, int right)
{
	//merge function

		//Size of the left array
	int leftSize = middle - left + 1;
	//Size of the right array
	int rightSize = right - middle;
	//Left array
	int* leftArray = new int[leftSize];
	//Right array
	int* rightArray = new int[rightSize];
	//Copy the left part of the array to the left array
	for (int i = 0; i < leftSize; i++)
	{
		leftArray[i] = array[left + i];
	}
	//Copy the right part of the array to the right array
	for (int i = 0; i < rightSize; i++)
	{
		rightArray[i] = array[middle + 1 + i];
	}
	//Index of the left array
	int leftIndex = 0;
	//Index of the right array
	int rightIndex = 0;
	//Index of the merged array
	int mergedIndex = left;
	//Merge the left and the right array
	while (leftIndex < leftSize && rightIndex < rightSize)
	{
		if (leftArray[leftIndex] <= rightArray[rightIndex])
		{
			array[mergedIndex] = leftArray[leftIndex];
			leftIndex++;
		}
		else
		{
			array[mergedIndex] = rightArray[rightIndex];
			rightIndex++;
		}
		mergedIndex++;
	}
	//Copy the remaining elements of the left array
	while (leftIndex < leftSize)
	{
		array[mergedIndex] = leftArray[leftIndex];
		leftIndex++;
		mergedIndex++;
	}
	//Copy the remaining elements of the right array
	while (rightIndex < rightSize)
	{
		array[mergedIndex] = rightArray[rightIndex];
		rightIndex++;
		mergedIndex++;
	}
}

void MainWindow::mergeSort(int* array, int left, int right)
{
	if (left < right)
	{
		int middle = (left + right) / 2;
		mergeSort(array, left, middle);
		mergeSort(array, middle + 1, right);
		merge(array, left, middle, right);
	}
}

void MainWindow::on_normalSearchButton_clicked()
{
}

void MainWindow::on_binarySearchButton_clicked()
{
	//Use binary search to find the number
}

void MainWindow::on_generateDataButton_clicked()
{
	QListWidget* list = ui->listWidget;
    QLabel* dataText = ui->dataSizeText;
	list->clear();
    dataText->setText("The Dataset Size is: " + QString::number(size));
    size = ui->datasetInput->text().toInt();
	array = new int[size];
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 100;
	}
	//Enter the array to the list
	for (int i = 0; i < size; i++)
	{
		//Add to the scrollbox
		list->addItem(QString::number(array[i]));
	}
}

void MainWindow::on_mergeSortButton_clicked()
{
	QListWidget* list = ui->listWidget;
    QLabel* method = ui->mergeMethodText;
    method->setText("Sorting Using Merge Sort");
	list->clear();
	//use merge sort on the array
	mergeSort(array, 0, size - 1);
	//Enter the array to the list
	for (int i = 0; i < size; i++)
	{
		list->addItem(QString::number(array[i]));
	}
}

void MainWindow::on_stlSortButton_clicked()
{
	QListWidget* list = ui->listWidget;
	list->clear();

	//Sort the array using stl sort algorithm
	//use stl sort on the array
	std::sort(array, array + size);
	//Enter the array to the list
	for (int i = 0; i < size; i++)
	{
		list->addItem(QString::number(array[i]));
	}
}

void MainWindow::on_findButton_clicked()
{
}
