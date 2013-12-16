# coding: utf-8
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
# require 'slopy/version'

Gem::Specification.new do |spec|
  spec.name          = "slopy"
  spec.version       = "0.0.1"
  spec.authors       = ["Ivan Shamatov"]
  spec.email         = ["status.enable@gmail.com"]
  spec.description   = %q{Write a gem description}
  spec.summary       = %q{Write a gem summary}
  spec.homepage      = ""
  spec.license       = "MIT"

  spec.files         = `git ls-files`.split($/)
  spec.executables   = spec.files.grep(%r{^bin/}) { |f| File.basename(f) }
  spec.test_files    = spec.files.grep(%r{^(test|spec|features)/})
  spec.require_paths = ["lib"]
  spec.extensions << "ext/slopy/extconf.rb"


  spec.add_development_dependency "bundler", "~> 1.3"
  spec.add_development_dependency "rake"
  spec.add_development_dependency "rake-compiler"
  spec.add_development_dependency "rspec"  
end
