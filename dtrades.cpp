#include "dtrades.hpp"

void dtrades::listprod(name seller, string metadata, name escrow, asset price) {
  require_auth(seller);
  require_recipient(seller);
  require_recipient(escrow);

  eosio_assert( price.is_valid(), "invalid price" );
  eosio_assert( price.amount > 0, "must specify positive price" );
  eosio_assert( price.symbol == S(4,EOS), "only EOS is accepted" );

  products.emplace( _self, [&]( auto& p ) {
    p.id = products.available_primary_key();
    p.seller = seller;
    p.escrow = escrow;
    p.metadata = metadata;
    p.price = price;
  });
}

void dtrades::tracking(uint64_t order_id, string details) {

}

void dtrades::shipping(uint64_t order_id, string details) {

}

void dtrades::apprbuyer(uint64_t order_id) {

}

void dtrades::apprseller(uint64_t order_id) {

}

void dtrades::purchase(name buyer, uint64_t product_id, uint64_t quantity) {

}

EOSIO_ABI(dtrades,
  (listprod)(tracking)(shipping)(apprbuyer)(apprseller)(purchase)
)
