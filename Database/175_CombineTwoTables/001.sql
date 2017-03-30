# Write your MySQL query statement below
#第一行写成SELECT FirstName, LastName, City, State也行
SELECT Person.FirstName, Person.LastName, Address.City, Address.State
FROM Person
LEFT JOIN Address
ON Person.PersonId = Address.PersonId;