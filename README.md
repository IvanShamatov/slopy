# Slopy

```Slopy::Calculator``` is attempt to implement slope one collaborative algorithm using Ruby C API, as a native extension.

## Methods

```ruby
Slopy::Calculator.cos(vector1, vector2)
# will calculate cosine similarity for two vectors

Slopy::Calculator.matrix(array_of_vectors)
# will calculate cosine similarity for each pair of vectors. 
# Attention: O(n*(n-1)/2)
```

## Installation

```
$ ruby ext/slopy/extconf.rb
$ rake compile 
$ irb -r ./lib/slopy