function frequency(m, bin)

maxRange = max(max(m));
range = round(255 / bin);

a = zeros(1, maxRange + 1);
[row, column] = size(m);

% frequency of each pixel
% pos 1 contains frequency of 0 intensity, pos 2 contains frequency of 1
% intensity and so on....
for r = 1:row
    for c = 1:column
        x = m(r,c)+1;
        a(x) = a(x) + 1;
    end
end


% storing cumulative frequencies according to bin
pos = 1;
binArray = zeros(1, bin);
for i = 1 : bin
    if pos + range - 1 > maxRange
        x = a(pos : maxRange);
    else
        x = a(pos : pos + range - 1);
    end
    binArray(i) = sum(x);
    pos = pos + range;
end

% displaying the histogram
horz = linspace(0, 255, bin);
bar(horz, binArray);