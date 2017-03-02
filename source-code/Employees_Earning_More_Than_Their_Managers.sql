# Write your MySQL query statement below
select E1.Name
AS Employee
from Employee E1
where E1.Salary > (select E2.Salary
                    from Employee E2
                    where E2.Id = E1.ManagerId)

#better solution
select E1.Name
as Employee
from Employee E1, Employee E2
where E1.salary > E2.salary
and E1.ManagerId = E2.Id;