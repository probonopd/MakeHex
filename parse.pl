#!/bin/perl
#for file in *.irp; do parse.pl $file; done
use File::Basename;
$file = basename($ARGV[0]);
$file =~ s/\.irp//;
print "\t{ \"$file\",\n";
open(INPUT, $ARGV[0]);
foreach (<INPUT>) {
	# remove comments & trim
	s/'.*$//;
	s/^\s+(\S)/\1/;
	s/(\S)\s+$/\1/;

	# ignore unwanted lines
	s/^Device=.*//i;
	s/^Function=.*//i;
	s/^Define M=.*//i;
	s/^Define L=.*//i;
	s/^Define T=.*//i;

	# skip empty lines
	next if(/^\s*$/);

	# keep
	print "\t\t\"$_\\n\"\n";
}
print "\t},\n";
