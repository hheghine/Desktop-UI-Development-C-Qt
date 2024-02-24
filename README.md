# Desktop-UI-Development-Cpp-Qt

---

## Task 1. Hello World Application
*Objective: Start with the basics by creating a Qt application that opens a window displaying "Hello, World!".*

### Detailed Explanation:
* `Setting Up:` Initialize a new Qt Widgets project in Qt Creator. This will be a straightforward application with a single main window.
* `UI Design:` Drag and drop a QLabel onto the main window using Qt Designer or create it programmatically in the main window's constructor. Set the label's text property to "Hello, World!".
* `Run and Test:` Compile and run your application to see a window displaying "Hello, World!". This task familiarizes you with the Qt development environment and basic UI elements.

---

## Task 2. Simple Click Counter
*Objective: Develop an application with a QPushButton. Each click increments a counter displayed on the screen.*

### Detailed Explanation:
* `UI Components:` Use QPushButton for the click action and QLabel to display the current count. Initialize the count to 0.
* `Signal-Slot Connection:` Connect the QPushButton's clicked signal to a custom slot in your application that increments the counter and updates the QLabel with the new value.
* `Layout:` Arrange the button and label using a QVBoxLayout.

---

## Task 3. Basic Form with Validation
*Objective: Create a form with QLineEdit widgets for user input and a QPushButton for submission. Implement validation to ensure fields are not empty.*

### Detailed Explanation:
* `Form Design:` Add several QLineEdit widgets for different inputs and a QPushButton for submission. Use QFormLayout for an organized structure.
* `Validation Logic:` In the slot connected to the button's clicked signal, check if any of the QLineEdit widgets are empty. If all fields are filled, show a QMessageBox with a success message; otherwise, show an error message.

---

## Task 4. Todo List Application
*Objective: Build a basic todo list allowing users to add and delete tasks.*

### Detailed Explanation:
* `Main Components:` Use a QLineEdit for input and a QListWidget to display tasks. Add buttons for adding and removing tasks.
* `Adding Tasks:` Connect the add button's clicked signal to a slot that adds the QLineEdit content as a new item in the QListWidget.
* `Removing Tasks:` Connect the remove button's clicked signal to a slot that removes the selected item from the QListWidget.

---

## Task 5. Text Editor
*Objective: Create a simple text editor capable of opening, editing, and saving text files.*

### Detailed Explanation:
* `Core Widget:` Use a QTextEdit for the main editing area. Add a menu bar with actions for Open, Save, and Exit.
* `File Operations:` Implement slots for each menu action using QFileDialog to open and save files, and QTextEdit's methods to read/write text.

