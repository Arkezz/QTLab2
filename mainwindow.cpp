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
	QLabel* status = ui->arrayStatus;
	method->setText("Sorting Using Merge Sort");
	status->setText("Sorted Array");
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
	QLabel* method = ui->mergeMethodText;
	QLabel* status = ui->arrayStatus;
	method->setText("Sorting Using STL Sort");
	status->setText("Sorted Array");
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
	//When the user clicks the button a qmessage popup shows whether the number is in the array or not. also shows the time needed (in nanoseconds) to search the array
	QListWidget* list = ui->listWidget;
	QLabel* method = ui->mergeMethodText;
	QLabel* status = ui->arrayStatus;
	method->setText("Searching Using Binary Search");
	status->setText("Sorted Array");
	list->clear();

	//use binary search on the array
    int number = ui->lineEdit->text().toInt();
	int left = 0;
	int right = size - 1;
	int middle = (left + right) / 2;
	bool found = false;

	//Start the timer
	auto start = std::chrono::high_resolution_clock::now();
	while (left <= right)
	{
		if (array[middle] == number)
		{
			found = true;
			break;
		}
		else if (array[middle] < number)
		{
			left = middle + 1;
		}
		else
		{
			right = middle - 1;
		}
		middle = (left + right) / 2;
	}
	//Stop the timer
	auto stop = std::chrono::high_resolution_clock::now();
	//Calculate the time
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	//Show the time
	QMessageBox msgBox;
	if (found)
	{
		msgBox.setText("The number is in the array");
	}
	else
	{
		msgBox.setText("The number is not in the array");
	}
	msgBox.setInformativeText("The time needed to search the array is: " + QString::number(duration.count()) + " nanoseconds");
	msgBox.exec();
}
