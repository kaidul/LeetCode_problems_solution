# Write your MySQL query statement below
select FirstName, LastName, City, State
from Person
left join Address
on Person.PersonId = Address.PersonId

#using clause
select FirstName, LastName, City, State
from Person
left join Address
using(PersonId)

#using 'natural left join'
select FirstName, LastName, City, State
from Person
natural left join Address