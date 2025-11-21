# Digital Clock

A simple **Digital Clock** application that displays the current time in either a **12-hour** or **24-hour** format. The clock can also handle **time adjustments** and an **optional alarm** feature.

## Features

- **Time Display**:

  - Display the current time in **12-hour** or **24-hour** format.
  - Show hours, minutes, and seconds (HH:MM:SS).
  - Toggle between AM/PM for 12-hour format.

- **Time Adjustment**:

  - Set or change the current time manually.
  - Supports setting hours, minutes, and seconds.

- **Alarm Function** (Optional):

  - Set an alarm to trigger at a specific time.
  - Displays an alert or triggers a sound when the alarm time is reached.

- **Real-Time Update**:

  - Automatically updates the time every second.
  - The display refreshes every time the time changes.

## Requirements

- **System Requirements**:

  - A computer or device with a terminal or GUI environment.
  - **C Compiler** (for C-based version).
  - (For GUI versions) GUI libraries like **GTK**, **Qt**, or **SDL**.

- **Libraries**:

  - For a console-based clock, you will need basic C libraries like `stdio.h`, `time.h`, and `stdlib.h`.
  - For GUI-based clocks, you may need libraries like `gtk+3.0` or `Qt5`.

## Installation

1. **Clone the repository**:

   ```
   git clone https://github.com/DeveloperJarvis/digital_clock.git
   ```

2. **Navigate to the project folder**:

   ```
   cd digital_clock
   ```

3. **Build the project** (if written in C):

   - For a console-based clock:

     ```bash
     gcc -o digital_clock digital_clock.c
     ```

   - For GUI-based implementations, follow the specific build instructions for the GUI library (e.g., `qmake` for Qt or `make` for GTK).

4. **Run the clock**:

   - Console-based:

     ```bash
     ./digital_clock
     ```

   - GUI-based: Run the compiled executable or follow the GUI framework-specific instructions.

## Usage

1. **Start the Clock**:
   Once started, the clock will display the current system time.

2. **Time Adjustment**:

   - Press the **Set Time** button or use a specific command to adjust the time.
   - Use the **Up/Down** arrows or input fields to modify hours, minutes, and seconds.

3. **Toggle Between 12/24-Hour Format**:

   - Use the **Format Toggle** button or type a command to switch between the 12-hour (AM/PM) format and 24-hour format.

4. **Set an Alarm** (Optional):

   - Use the **Set Alarm** button to enter the desired alarm time.
   - The clock will trigger an alert (or sound) when the time matches the alarm setting.

5. **Exit the Clock**:

   - To exit the clock, simply close the application window or press **Ctrl+C** (for console applications).

## Screenshots (Optional)

If your clock has a GUI, you can include screenshots here.

Example:

```
![Clock Screenshot](path/to/screenshot.png)
```

## Development

### How It Works

The clock uses the following components:

- **Time Representation**: Time is represented using a structure or array, including hours, minutes, and seconds.
- **Time Update Mechanism**: The clock updates every second using a timer or system time.
- **Display Update**: The clock display is refreshed regularly, either through a terminal interface (in text format) or a graphical interface.
- **Alarm Functionality**: The clock can store an alarm time and check if the current time matches the set alarm time.
- **User Input Handling**: Users can adjust the time, set the alarm, or toggle the time format.

### Code Structure

1. **Main Program** (`digital_clock.c`): The main program that handles time updates, display management, and user input.
2. **Time Functions** (`time_utils.c`): Contains functions for setting, updating, and formatting time.
3. **Alarm Logic** (`alarm.c`): If implemented, this file handles the alarm setting, checking, and triggering.

### How to Contribute

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make changes and commit them (`git commit -m 'Add new feature'`).
4. Push to your branch (`git push origin feature-branch`).
5. Open a pull request.

## License

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.

## Acknowledgements

- Special thanks to [name or resource] for providing inspiration or libraries used in this project.
- The alarm sound feature uses [tool or library] to provide sound functionality.

### Install GCC

For Ubuntu:

```bash
sudo apt install gcc -y
```

## Compile using gcc

```bash
gcc -g -Wall -Wextra -o digital_clock.out digital_clock.c
```

## Execute the object file

1. Simple execute

```bash
./digital_clock.out
```

## For Windows:

**NOTE** Clang will throw error for fopen is deprecated

### Install clang

1. Install Microsoft Visual Studio
2. Add to your windows path:
3. Win+ R > sysdm.cpl
4. Advanced > Environment Variables
5. System variables > Path > Edit
6. Add (C:\Program Files\Microsoft Visual Studio\18\<Version>\VC\Tools\Llvm\bin
   )

### Compile using clang

```bash
clang -c digital_clock.c -o digital_clock.o
clang digital_clock.o -o digital_clock_x64.exe
```

### Execute the object file

1. Simple execute

```bash
# encrypting
digital_clock_x64.exe
```

## Creating tag

```bash
# 1. Check existing tags
git tag
# 2. Create a valid tag
git tag -a v1.0.0 -m "Release version 1.0.0"
# or lightweight tag
git tag v1.0.0
# push tag to remote
git push origin v1.0.0
```
