function [m0, m1, m2, m3, m4, m5, m6, m7] = bit_plane_slicing(m)

[row, column] = size(m);
m0 = zeros(row, column);
m1 = zeros(row, column);
m2 = zeros(row, column);
m3 = zeros(row, column);
m4 = zeros(row, column);
m5 = zeros(row, column);
m6 = zeros(row, column);
m7 = zeros(row, column);

for r = 1 : row
    for c = 1 : column
        x = m(r,c);
        if bitand(x, 2^7) ~= 0
            m7(r,c) = x;
        end
        if bitand(x, 2^6) ~= 0
            m6(r,c) = x;
        end
        if bitand(x, 2^5) ~= 0
            m5(r,c) = x;
        end
        if bitand(x, 2^4) ~= 0
            m4(r,c) = x;
        end
        if bitand(x, 2^3) ~= 0
            m3(r,c) = x;
        end
        if bitand(x, 2^2) ~= 0
            m2(r,c) = x;
        end
        if bitand(x, 2^1) ~= 0
            m1(r,c) = x;
        end
        if bitand(x, 2^0) ~= 0
            m0(r,c) = x;
        end
    end
end
end