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

void dtrades::editprod(uint64_t id, string metadata, name escrow, asset price) {
  auto product = products.get(id, "invalid product id");

  require_auth(product.seller);
  require_recipient(escrow);

  eosio_assert( price.is_valid(), "invalid price" );
  eosio_assert( price.amount > 0, "must specify positive price" );
  eosio_assert( price.symbol == S(4,EOS), "only EOS is accepted" );

  products.modify( product, _self, [&]( auto& p ) {
    p.escrow = escrow;
    p.metadata = metadata;
    p.price = price;
  });
}

void dtrades::purchase(name buyer, uint64_t product_id, uint64_t quantity) {
  require_auth(buyer);
  auto product = products.get(product_id, "invalid product id");

  eosio_assert(quantity > 0, "must purchase positive quantities");
  uint64_t cost = quantity * product.price.amount;
  auto total_price = asset(cost,S(4,EOS));

  orders.emplace( _self, [&]( auto& p ) {
    p.id = orders.available_primary_key();
    p.product_id = product.id;
    p.quantity = quantity;
    p.total_price = total_price;
    p.seller = product.seller;
    p.escrow = product.escrow;
    p.buyer = buyer;
    p.status = "Paid";
  });

  action(
    permission_level{ buyer, N(active) },
    N(eosio.token), N(transfer),
    std::make_tuple(buyer, _self, total_price, "Purchase from DTRADES")
  ).send();
}

void dtrades::tracking(uint64_t order_id, string details) {

}

void dtrades::shipping(uint64_t order_id, string details) {

}

void dtrades::apprbuyer(uint64_t order_id) {

}

void dtrades::apprseller(uint64_t order_id) {

}



EOSIO_ABI(dtrades,
  (listprod)(editprod)(purchase)(tracking)(shipping)(apprbuyer)(apprseller)
)
