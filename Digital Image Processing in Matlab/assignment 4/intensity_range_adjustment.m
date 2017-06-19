function m = intensity_range_adjustment(m)

lower_limit = 0;
upper_limit = 255;
minimum = min(min(m));

m = m - minimum + lower_limit;
maximum = max(max(m));

m = m / maximum * upper_limit;
m = uint8(m);

end