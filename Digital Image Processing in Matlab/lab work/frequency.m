% frequency of each pixel
function a = frequency(m)

range = max(max(m));

a = zeros(1, range+1);
[row, column] = size(m);

for r = 1:row
    for c = 1:column
        x = m(r,c)+1;
        a(x) = a(x) + 1;
    end
end
end
