local module = require('@module')

local a = 123
local b = 321
local c = module.add_numbers(a, b)
print(`{nameof(a)} + {nameof(b)} = {nameof(c)}`)
print(`{a} + {b} = {c}`)

local dlmodule = dlimport.load('@module/mydlmodule')
local print_hello: ()->() = dlmodule:importfunction('print_hello')
print_hello()
