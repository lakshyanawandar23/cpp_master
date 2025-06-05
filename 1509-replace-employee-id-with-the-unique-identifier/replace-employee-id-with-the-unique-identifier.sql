# Write your MySQL query statement below
select EmployeeUNI.unique_id,Employees.name from Employees left join EmployeeUNI ON Employees.id=EmployeeUNI.id;