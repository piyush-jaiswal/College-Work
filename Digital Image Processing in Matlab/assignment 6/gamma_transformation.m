function m = gamma_transformation(c, gamma, m)
    m = double(m);
    m = c .* power(m, gamma);
    m = mat2gray(m);
end