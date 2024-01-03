#Function to implement Sieve of Eratosthenes
sieve_of_eratosthenes = function(limit){
  if(limit >= 2) {
    numbers = 2:limit
    
    for (p in numbers) {
      if (p^2 > limit) {
        break
      }
      numbers = numbers[numbers == p | numbers %% p != 0]
    }
    return(numbers)
  }
  else {
    return(numeric(0))
  }
}
prime_numbers = sieve_of_eratosthenes(30)
print(prime_numbers)