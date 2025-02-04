export type public = {
    add_numbers: (a: number, b: number) -> number
}

return dlimport.require("mydlmodule") :: public
