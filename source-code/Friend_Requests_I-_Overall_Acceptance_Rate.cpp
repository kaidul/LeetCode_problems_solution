select 
ifnull
(
    (
        select round
        (
            count(distinct requester_id, accepter_id) / count(distinct sender_id, send_to_id),
            2
        )
        from request_accepted, friend_request
    ), 
    0
)
as accept_rate