#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    // Add a new task
    void addTask(const string& description) {
        tasks.push_back(Task(description));
        cout << "Task added: " << description << endl;
    }

    // Delete a task by its index
    void deleteTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            cout << "Task deleted: " << tasks[index].description << endl;
            tasks.erase(tasks.begin() + index);
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    // Mark a task as complete or incomplete by its index
    void markTask(int index, bool complete) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = complete;
            cout << "Task marked as " << (complete ? "complete" : "incomplete") << ": " << tasks[index].description << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    // View all tasks with their status
    void viewTasks() {
        cout << "To-Do List:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description << " - ";
            cout << (tasks[i].completed ? "Complete" : "Pending") << endl;
        }
    }
};

int main() {
    ToDoList todo;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Delete Task" << endl;
        cout << "3. Mark Task as Complete" << endl;
        cout << "4. Mark Task as Incomplete" << endl;
        cout << "5. View Tasks" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter task description: ";
                string description;
                cin.ignore(); // Ignore newline character left in the input buffer
                getline(cin, description);
                todo.addTask(description);
                break;
            }
            case 2: {
                cout << "Enter task index to delete: ";
                int index;
                cin >> index;
                todo.deleteTask(index - 1); // Adjust index to 0-based
                break;
            }
            case 3: {
                cout << "Enter task index to mark as complete: ";
                int index;
                cin >> index;
                todo.markTask(index - 1, true); // Adjust index to 0-based
                break;
            }
            case 4: {
                cout << "Enter task index to mark as incomplete: ";
                int index;
                cin >> index;
                todo.markTask(index - 1, false); // Adjust index to 0-based
                break;
            }
            case 5:
                todo.viewTasks();
                break;
            case 6:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}
