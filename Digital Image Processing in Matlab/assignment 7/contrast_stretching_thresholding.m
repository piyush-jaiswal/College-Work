function m = contrast_stretching_thresholding(r1, r2, factor, m)

[row, column] = size(m);

for r = 1 : row
    for c = 1 : column
        if m(r,c) >= r1 && m(r,c) <= r2
            m(r,c) = mod(m(r,c) + factor, 255);
        else
            m(r,c) = 0;
        end
    end
end
end