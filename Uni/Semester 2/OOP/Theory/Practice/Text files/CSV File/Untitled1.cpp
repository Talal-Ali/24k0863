#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

#define MAX_ROWS 100
#define MAX_COLS 10
#define MAX_FIELD_LEN 100

class CSVHandler {
private:
    string filename;
    string data[MAX_ROWS][MAX_COLS];
    int rowCount = 0;
    int colCount = 0;

public:
    CSVHandler(const string& fname) : filename(fname) {
        loadData();
    }

    void loadData() {
        rowCount = 0;
        ifstream file(filename);
        string line;

        while (getline(file, line) && rowCount < MAX_ROWS) {
            istringstream ss(line);
            string value;
            int col = 0;
            while (getline(ss, value, ',') && col < MAX_COLS) {
                data[rowCount][col] = value;
                col++;
            }
            colCount = max(colCount, col);
            rowCount++;
        }

        file.close();
    }

    void saveData() {
        ofstream file(filename);
        for (int i = 0; i < rowCount; ++i) {
            for (int j = 0; j < colCount; ++j) {
                file << data[i][j];
                if (j < colCount - 1) file << ",";
            }
            file << "\n";
        }
        file.close();
    }

    void readCSV() const {
        cout << "\n[CSV CONTENTS]:\n";
        for (int i = 0; i < rowCount; ++i) {
            for (int j = 0; j < colCount; ++j) {
                cout << data[i][j] << "\t";
            }
            cout << "\n";
        }
    }

    void writeCSV(const char newData[MAX_ROWS][MAX_COLS][MAX_FIELD_LEN], int newRows, int newCols) {
        rowCount = newRows;
        colCount = newCols;
        for (int i = 0; i < newRows; ++i) {
            for (int j = 0; j < newCols; ++j) {
                data[i][j] = newData[i][j];
            }
        }
        saveData();
    }

    void appendRows(const char rows[][MAX_COLS][MAX_FIELD_LEN], int count) {
        for (int r = 0; r < count && rowCount < MAX_ROWS; ++r) {
            for (int i = 0; i < colCount; ++i) {
                data[rowCount][i] = rows[r][i];
            }
            rowCount++;
        }
        saveData();
    }

    void editCell(int rowIdx, int colIdx, const char* newValue) {
        if (rowIdx < rowCount && colIdx < colCount) {
            data[rowIdx][colIdx] = newValue;
            saveData();
        } else {
            cerr << "Invalid index.\n";
        }
    }

    void deleteRow(int rowIdx) {
        if (rowIdx >= 0 && rowIdx < rowCount) {
            for (int i = rowIdx; i < rowCount - 1; ++i) {
                for (int j = 0; j < colCount; ++j) {
                    data[i][j] = data[i + 1][j];
                }
            }
            rowCount--;
            saveData();
        } else {
            cerr << "Invalid row index.\n";
        }
    }
};

int main() {
    CSVHandler handler("data.csv");

    // Initial display
    handler.readCSV();

    // Appending multiple rows
    cout << "\n[Appending Multiple Rows]\n";
    char moreRows[2][MAX_COLS][MAX_FIELD_LEN] = {
        {"Eve", "28", "Germany"},
        {"Leo", "31", "France"}
    };
    handler.appendRows(moreRows, 2);
    handler.readCSV();

    // Editing a cell
    cout << "\n[Editing Cell (Row 1, Col 1 -> '35')]\n";
    handler.editCell(1, 1, "35");
    handler.readCSV();

    // Deleting a row
    cout << "\n[Deleting Row 0]\n";
    handler.deleteRow(0);
    handler.readCSV();

    // Overwriting with new data
    cout << "\n[Overwriting Entire CSV]\n";
    char newData[4][MAX_COLS][MAX_FIELD_LEN] = {
        {"Name", "Age", "Country"},
        {"Anna", "23", "Italy"},
        {"Mark", "37", "Spain"},
        {"Sara", "29", "Sweden"}
    };
    handler.writeCSV(newData, 4, 3);
    handler.readCSV();

    return 0;
}
