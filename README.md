# dtrades-contract


## Set permission for buyer/seller

`kcleos set account permission dtradebuyer1 active '{"threshold":1,"keys":[{"key":"EOS77acvYqW1VZo6Zm4PynAdeiJMLmtgW8cxxUVPAsqg4i34GjYRC","weight":1}],"accounts":[{"permission":{"actor":"dtradesdapp1","permission":"eosio.code"},"weight":1}]}' owner -p dtradebuyer1`

`kcleos set account permission dtradesdapp1 active '{"threshold":1,"keys":[{"key":"EOS8jmJMH636MERGweMcwLZa8NJ8MKqtFqFsTpjHv6qarpuTMwUxy","weight":1}],"accounts":[{"permission":{"actor":"dtradesdapp1","permission":"eosio.code"},"weight":1}]}' owner -p dtradesdapp1`

## Create

`cleos push action dtradesdapp1 listprod '["dtradesdapp1","jsonmetadata","dtradesdapp1","10.0000 EOS"]' -p dtradesdapp1`

`cleos push action dtradesdapp1 purchase '["dtradebuyer1",0,1,"encrypted shipping details"]' -p dtradebuyer1`
