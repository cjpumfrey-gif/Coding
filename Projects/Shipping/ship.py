weight = 1.5

#Ground Shipping

if weight <= 2:
  ground_shipping_price = 20 + 1.5 * weight
elif 2 < weight and weight <= 6:
  ground_shipping_price = 20 + 3 * weight
elif 6 < weight and weight <= 10:
  ground_shipping_price = 20 + 4 * weight
else: 
  ground_shipping_price = 20 + 4.75 * weight

#Premium Shipping
premium_shipping = 125


#Drone Shipping
if weight <= 2:
  drone_shipping_price = 4.5 * weight
elif 2 < weight and weight <= 6:
  drone_shipping_price = 9 * weight
elif 6 < weight and weight <= 10:
  drone_shipping_price = 12 * weight
else:
  drone_shipping_price = 14.25 * weight

#dictionary of key options
shipping_options = {
    ground_shipping_price: "Ground Shipping",
    premium_shipping: "Premium Shipping",
    drone_shipping_price: "Drone Shipping"
}



cheapest_price = min(shipping_options.keys())
cheapest_service = shipping_options[cheapest_price]

print(f"The cheapest shipping option is **{cheapest_service}**.")
print(f"The cost will be: ${cheapest_price:.2f}")



