function m = apply_log(c, m)
    m = double(m);
    m = round(c .* log10(1 + m));
    m = mat2gray(m);
end