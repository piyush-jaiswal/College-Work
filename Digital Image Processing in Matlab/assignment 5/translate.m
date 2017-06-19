function x = translate(x0, y0, m)

[row, column] = size(m);
x = zeros(row, column);

for r = 1:row
    for c = 1:column
        a = mod((r+y0), row);
        b = mod((c+x0),column);
        if a > 0 && a < row && b > 0 && b < column
        x(a,b) = m(r,c);
        end
    end
end
end
