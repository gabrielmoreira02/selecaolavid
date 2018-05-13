

local tests = require ('tests')
local ASSERT = tests.ASSERT
local ASSERT_ERROR = tests.ASSERT_ERROR




--TESTANDO PRIMEIRAMENTE SE TODAS AS OPERAÇÕES FUNCIONAM
print("testando se as operações funcionam, aleatoriamente")
ASSERT(bit32.arshift(10,2))
ASSERT(bit32.band(1,1))
ASSERT(bit32.bnot(234))
ASSERT(bit32.bor(1,3))
ASSERT(bit32.btest(324))
ASSERT(bit32.bxor(3,10))
ASSERT(bit32.extract(3,2))
ASSERT(bit32.replace(3,5,2))
ASSERT(bit32.lrotate(4,3))
ASSERT(bit32.lshift(54,13))
ASSERT(bit32.rrotate(46,1))
ASSERT(bit32.rshift(32,5))

--OPERAÇÕES OK. TESTANDO AGORA SUAS LÓGICAS (MOSTRADAS NO LINK FORNECIDO)
print("Operacoes OK. Testando a logica:")
x= 8
disp =3
b= 1

--logica encontrada no site
ASSERT(bit32.bnot(x) == (-1 - x) % 2^32)
ASSERT(bit32.lrotate(x, disp) == bit32.lrotate(x, disp % 32))
ASSERT(bit32.lshift(b, disp) == (b * 2^disp) % 2^32)
ASSERT(bit32.rrotate(x, disp) == bit32.rrotate(x, disp % 32))
ASSERT(bit32.rshift(b, disp) == math.floor(b % 2^32 / 2^disp))

--lógica básica vista pelo aluno (excluindo as operacoes de cima)
ASSERT(bit32.band(1,1)==1)
ASSERT(bit32.band(0,1)==0)
ASSERT(bit32.bor(0,1)==1)
ASSERT(bit32.bor(0,0)==0)
ASSERT(bit32.btest(0)==false)
ASSERT(bit32.btest(1)==true)
ASSERT(bit32.bxor(0,1)==1)
ASSERT(bit32.bxor(1,1)==0)

-- NESSE PONTO, TODAS AS LÓGICAS ESTÃO IMPLEMENTADAS CORRETAMENTE
-- IMPRIMINDO ALGUNS RESULTADOS
print("Imprimindo alguns resultados")
print(bit32.arshift(10,2))
print(bit32.band(0,0))
print(bit32.bnot(0))
print(bit32.bor(0,1))
print(bit32.btest(0))
print(bit32.bxor(1,1))
print(bit32.extract(3,2))
print(bit32.replace(3,5,2))
print(bit32.lrotate(4,3))
print(bit32.lshift(54,13))
print(bit32.rrotate(46,1))
print(bit32.rshift(32,5))


print("Todas as operacoes estao implementadas corretamente")