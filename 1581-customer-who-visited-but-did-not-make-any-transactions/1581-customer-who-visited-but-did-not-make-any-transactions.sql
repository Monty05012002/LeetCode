/* Write your T-SQL query statement below */
Select a.customer_id , count(a.visit_id)  as count_no_trans  from 
visits a left join
transactions b on a.visit_id=b.visit_id
where b.transaction_id is Null
Group by customer_id
