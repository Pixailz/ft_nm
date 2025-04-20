# ft_nm

- [elf header](https://refspecs.linuxfoundation.org/elf/gabi4+/ch4.eheader.html)

## TODO

- fix this case

```diff
< 0000000000010060 w data_start
---
> 0000000000010060 W data_start
```

- implement default behavior
   - no ac == 1, a.out
   - ac > 2, print file name
