# dtrades-contract


## Set permission for buyer/seller

`kcleos set account permission dtradebuyer1 active '{"threshold":1,"keys":[{"key":"EOS77acvYqW1VZo6Zm4PynAdeiJMLmtgW8cxxUVPAsqg4i34GjYRC","weight":1}],"accounts":[{"permission":{"actor":"dtradesdapp1","permission":"eosio.code"},"weight":1}]}' owner -p dtradebuyer1`

`kcleos set account permission dtradesdapp1 active '{"threshold":1,"keys":[{"key":"EOS8jmJMH636MERGweMcwLZa8NJ8MKqtFqFsTpjHv6qarpuTMwUxy","weight":1}],"accounts":[{"permission":{"actor":"dtradesdapp1","permission":"eosio.code"},"weight":1}]}' owner -p dtradesdapp1`

`kcleos set account permission dtradeseller active '{"threshold":1,"keys":[{"key":"EOS5x2uxVezW7e4S5TQu9N7iFhZdFdzmkZzrSFcUt2xMqPcEVmQ2H","weight":1}],"accounts":[{"permission":{"actor":"dtradesdapp1","permission":"eosio.code"},"weight":1}]}' owner -p dtradeseller`

## Create

`kcleos push action dtradesdapp1 listprod '["dtradeseller","jsonmetadata","dtradesdapp1","10.0000 EOS"]' -p dtradeseller`

## Purchase

`kcleos push action dtradesdapp1 purchase '["dtradebuyer1",1,1,"encrypted shipping details"]' -p dtradebuyer1`

`kcleos push action dtradesdapp1 tracking '[22,"encrypted tracking details"]' -p dtradeseller`

`kcleos push action dtradesdapp1 received '[22]' -p dtradebuyer1`
