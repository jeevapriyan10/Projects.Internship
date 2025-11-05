#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Task {
public:
    int id;
    string title;
    string description;
    string status;

    Task(int id, string title, string description, string status = "Pending") {
        this->id = id;
        this->title = title;
        this->description = description;
        this->status = status;
    }

    void display() const {
        cout << "[" << id << "] " << title << " - " << description << " (" << status << ")\n";
    }
};

void createTask(vector<Task>& tasks) {
    string title, desc;
    cin.ignore();
    cout << "Enter task title: ";
    getline(cin, title);
    cout << "Enter task description: ";
    getline(cin, desc);

    if (title.empty()) {
        cout << "Title cannot be empty!\n";
        return;
    }

    int id = tasks.size() + 1;
    tasks.push_back(Task(id, title, desc));
    cout << "Task created successfully!\n";
}

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    cout << "\nTask List:\n";
    for (const auto& t : tasks) t.display();
}

void updateTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to update.\n";
        return;
    }

    int id;
    cout << "Enter Task ID to update: ";
    cin >> id;

    auto it = find_if(tasks.begin(), tasks.end(), [&](Task& t){ return t.id == id; });

    if (it != tasks.end()) {
        cin.ignore();
        string newTitle, newDesc, newStatus;

        cout << "Enter new title (leave blank to keep current): ";
        getline(cin, newTitle);
        if (!newTitle.empty()) it->title = newTitle;

        cout << "Enter new description (leave blank to keep current): ";
        getline(cin, newDesc);
        if (!newDesc.empty()) it->description = newDesc;

        cout << "Enter new status (Pending/Completed): ";
        getline(cin, newStatus);
        if (!newStatus.empty()) it->status = newStatus;

        cout << "Task updated successfully!\n";
    } else {
        cout << "Task not found!\n";
    }
}

void deleteTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to delete.\n";
        return;
    }

    int id;
    cout << "Enter Task ID to delete: ";
    cin >> id;

    auto it = find_if(tasks.begin(), tasks.end(), [&](Task& t){ return t.id == id; });

    if (it != tasks.end()) {
        tasks.erase(it);
        cout << "Task deleted successfully!\n";

        for (int i = 0; i < tasks.size(); ++i)
            tasks[i].id = i + 1;
    } else {
        cout << "Task not found!\n";
    }
}

void showMenu() {
    cout << "\n===== TASK MANAGER =====\n";
    cout << "1. Create Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Update Task\n";
    cout << "4. Delete Task\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    vector<Task> tasks;
    int choice;

    while (true) {
        showMenu();

        cin >> choice;
        if (cin.fail()) {
            cout << "Invalid input! Enter a number.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (choice) {
            case 1: createTask(tasks); break;
            case 2: viewTasks(tasks); break;
            case 3: updateTask(tasks); break;
            case 4: deleteTask(tasks); break;
            case 5: cout << "Exit\n"; return 0;
            default: cout << "Invalid choice. Try again.\n"; break;
        }
    }
}
