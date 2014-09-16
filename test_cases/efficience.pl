use warnings;
use strict;

my $vectors_file = "vectors.txt";

open(my $file, '<', $vectors_file) or die $!;
while (<$file>) {
  my $input = substr($_,0,-1);
  print $input;
  my $execucao = `time sh -c \"echo $input \| ./radix_test\"`;
  print $execucao;
}
