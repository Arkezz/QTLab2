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
	normalSearch = true;
	ui->searchMethodText->setText("Using Normal Search");
}

void MainWindow::on_binarySearchButton_clicked()
{
	normalSearch = false;
	ui->searchMethodText->setText("Using Binary Search");
}

void MainWindow::on_generateDataButton_clicked()
{
	QListWidget* list = ui->listWidget;
	QLabel* dataText = ui->dataSizeText;
	size = ui->datasetInput->text().toInt();
	list->clear();
	dataText->setText("The Dataset Size is: " + QString::number(size));
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

	//use stl sort on the array and store the time it took to sort the array
	auto start = std::chrono::high_resolution_clock::now();
	std::sort(array, array + size);
	auto end = std::chrono::high_resolution_clock::now();
	sortTime = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

	//Enter the array to the list
	for (int i = 0; i < size; i++)
	{
		list->addItem(QString::number(array[i]));
	}
}

void MainWindow::on_findButton_clicked()
{
	number = ui->numberInput->text().toInt();
	int searchTime;
	//When the user clicks the button a qmessage popup shows whether the number is in the array or not. also shows the time needed (in nanoseconds) to search the array

	//Start the timer
	auto start = std::chrono::high_resolution_clock::now();
	//Find the number and store the time it took to find the number in the array then display the result in qmessagebox whther the number is found and how long it took to sort/find if it isnt found display a message saying the number is not found
	if (normalSearch)
	{
		for (int i = 0; i < size; i++)
		{
			if (array[i] == number)
			{
				searchTime = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - start).count();
                QMessageBox::information(this, "Number Found", "The number is found in the array and it took " + QString::number(searchTime) + " nanoseconds to find the number\n" + "The time it took to sort the array is: " + QString::number(sortTime) + " nanoseconds");
				return;
			}
		}
		QMessageBox::information(this, "Number Not Found", "The number is not found in the array");
	}
	else
	{
		int left = 0;
		int right = size - 1;
		while (left <= right)
		{
			int middle = (left + right) / 2;
			if (array[middle] == number)
			{
				searchTime = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - start).count();
                QMessageBox::information(this, "Number Found", "The number is found in the array and it took " + QString::number(searchTime) + " nanoseconds to find the number\n" + "The time it took to sort the array is: " + QString::number(sortTime) + " nanoseconds");
				return;
			}
			else if (array[middle] < number)
			{
				left = middle + 1;
			}
			else
			{
				right = middle - 1;
			}
		}
		QMessageBox::information(this, "Number Not Found", "The number is not found in the array");
	}
}

