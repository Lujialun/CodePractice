select Person.FirstName,Person.LastName,Address.City,Address.State
from Person
left join Address
on Person.PersonId=Address.PersonId 
-- 考察outjoin与injoin的区别

select COSTs.PROD_ID COSTs.PROMO_ID 
form COSTS 
where UNIT_COST > UNIT_PRICE*1.25
order by UNIT_COST desc
