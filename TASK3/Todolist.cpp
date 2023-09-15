#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int taskID;

struct Task {
    int id;
    string description;
};

void addTask() {
    system("cls");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t               WELCOME TO Your ToDo List Manager                       " << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl;

    Task newTask;
    cout << "\n\tEnter a new task: ";
    cin.get();
    getline(cin, newTask.description);
    taskID++;

    ofstream taskFile;
    taskFile.open("tasks.txt", ios::app);
    taskFile << "\n" << taskID;
    taskFile << "\n" << newTask.description;
    taskFile.close();

    ofstream idFile;
    idFile.open("task_id.txt");
    idFile << taskID;
    idFile.close();

    char ch;
    cout << "Do you want to add more tasks? (y/n)" << endl;
    cin >> ch;

    if (ch == 'y') {
        addTask();
    }
    else {
        cout << "\n\tTask has been added successfully";
        return;
    }
}

void displayTask(const Task& task) {
    cout << "\n\tTask ID: " << task.id;
    cout << "\n\tDescription: " << task.description;
}

void listTasks() {
    system("cls");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t               WELCOME TO Your ToDo List Manager                       " << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl;

    Task task;
    ifstream taskFile;
    taskFile.open("tasks.txt");
    cout << "\n\t------------------Your Current Tasks--------------------";
    
    while (!taskFile.eof()) {
        taskFile >> task.id;
        taskFile.ignore();
        getline(taskFile, task.description);
        displayTask(task);
    }
    
    taskFile.close();
}

int searchTask() {
    system("cls");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t               WELCOME TO Your ToDo List Manager                       " << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl;

    int searchID;
    cout << "\n\tEnter the task ID to search: ";
    cin >> searchID;
    Task task;
    ifstream taskFile;
    taskFile.open("tasks.txt");

    while (!taskFile.eof()) {
        taskFile >> task.id;
        taskFile.ignore();
        getline(taskFile, task.description);
        if (task.id == searchID) {
            displayTask(task);
            return searchID;
        }
    }
}

void deleteTask() {
    system("cls");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t               WELCOME TO Your ToDo List Manager                       " << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl;

    int taskToDelete = searchTask();
    cout << "\n\tDo you want to delete this task? (y/n): ";
    char choice;
    cin >> choice;

    if (choice == 'y') {
        Task task;
        ofstream tempFile;
        tempFile.open("temp_tasks.txt");
        ifstream taskFile;
        taskFile.open("tasks.txt");

        while (!taskFile.eof()) {
            taskFile >> task.id;
            taskFile.ignore();
            getline(taskFile, task.description);
            if (task.id != taskToDelete) {
                tempFile << "\n" << task.id;
                tempFile << "\n" << task.description;
            }
        }

        taskFile.close();
        tempFile.close();
        remove("tasks.txt");
        rename("temp_tasks.txt", "tasks.txt");
        cout << "\n\tTask deleted successfully";
    }
    else {
        cout << "\n\tRecord not deleted";
    }
}

void updateTask() {
    system("cls");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t               WELCOME TO Your ToDo List Manager                       " << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl;

    int taskToUpdate = searchTask();
    cout << "\n\tDo you want to update this task? (y/n): ";
    char choice;
    cin >> choice;

    if (choice == 'y') {
        Task newTaskData;
        cout << "\n\tEnter the updated task description: ";
        cin.get();
        getline(cin, newTaskData.description);
        Task task;
        ofstream tempFile;
        tempFile.open("temp_tasks.txt");
        ifstream taskFile;
        taskFile.open("tasks.txt");

        while (!taskFile.eof()) {
            taskFile >> task.id;
            taskFile.ignore();
            getline(taskFile, task.description);
            if (task.id != taskToUpdate) {
                tempFile << "\n" << task.id;
                tempFile << "\n" << task.description;
            }
            else {
                tempFile << "\n" << task.id;
                tempFile << "\n" << newTaskData.description;
            }
        }

        taskFile.close();
        tempFile.close();
        remove("tasks.txt");
        rename("temp_tasks.txt", "tasks.txt");
        cout << "\n\tTask updated successfully";
    }
    else {
        cout << "\n\tRecord not updated";
    }
}

int main() {
    system("cls");
    system("Color E0");
    system("title ToDoApp @copyassignment");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t               WELCOME TO Your ToDo List Manager                       " << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl;

    ifstream idFile;
    idFile.open("task_id.txt");
    if (!idFile.fail()) {
        idFile >> taskID;
    }
    else {
        taskID = 0;
    }
    idFile.close();

    while (true) {
        cout << endl << endl;
        cout << "\n\t1. Add a New Task";
        cout << "\n\t2. View Tasks";
        cout << "\n\t3. Search Task";
        cout << "\n\t4. Delete Task";
        cout << "\n\t5. Update Task";

        int choice;
        cout << "\n\tEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                listTasks();
                break;
            case 3:
                searchTask();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                updateTask();
                break;
            default:
                cout << "\n\tInvalid choice, please try again";
        }
    }

    return 0;
}
