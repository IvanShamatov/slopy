require 'rspec'
require './lib/slopy'


describe Slopy::Calculator do
  it "should calculate cosine similarity for two vectors" do 
    expect( subject.cos([0,1],[1,0]) ).to eq(0.0)
    expect( subject.cos([1,1],[1,1]) ).to eq(0.9999999999999998)
    expect( subject.cos([1,1],[1,0]) ).to eq(0.7071067811865475)
  end
end