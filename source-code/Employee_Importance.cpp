/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
    int getImportance(int id, vector<Employee*> const& employees, unordered_map<int, int>& employeeMap) {
        int totalImportance = employees[employeeMap[id]]->importance;
        for(int subordinateId : employees[employeeMap[id]]->subordinates) {
            totalImportance += getImportance(subordinateId, employees, employeeMap);
        }
        return totalImportance;
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, int> employeeMap;
        for(int i = 0; i < employees.size(); i++) {
            employeeMap[employees[i]->id] = i;
        }
        return getImportance(id, employees, employeeMap);
    }
};