select max(Salary)
as SecondHighestSalary
from Employee
where Salary < (select max(Salary) from Employee)
order by Salary desc;

#little slower
select max(Salary)
as SecondHighestSalary
from Employee
where Salary < (select max(Salary) from Employee);