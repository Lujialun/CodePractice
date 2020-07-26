select
(select distinct 
        Salary
    from
        Employee
    order by Salary DESC
    limit 1 offset 1) as  SecondHighestSalary
;

--limit 显示个数 offset跳过个数