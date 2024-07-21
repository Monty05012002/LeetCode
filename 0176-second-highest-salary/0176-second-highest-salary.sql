/* Write your T-SQL query statement below */
Select MAX(salary) as SecondHighestSalary from Employee where salary <> (Select MAX(salary) from Employee)