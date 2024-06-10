
#include "nx_api.h"

#ifdef __PRODUCT_NETXDUO__

#include "netx_mdns_test.h"

/* Frame (269 bytes) */
static const unsigned char pkt1[269] = {
0x01, 0x00, 0x5e, 0x00, 0x00, 0xfb, 0x00, 0x11, /* ..^..... */
0x22, 0x33, 0x44, 0x57, 0x08, 0x00, 0x45, 0x00, /* "3DW..E. */
0x00, 0xff, 0x00, 0x01, 0x40, 0x00, 0xff, 0x11, /* ....@... */
0x8f, 0xaf, 0x0a, 0x00, 0x00, 0x42, 0xe0, 0x00, /* .....B.. */
0x00, 0xfb, 0x14, 0xe9, 0x14, 0xe9, 0x00, 0xeb, /* ........ */
0x13, 0x25, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, /* .%...... */
0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x0b, 0x41, /* .......A */
0x52, 0x4d, 0x4d, 0x44, 0x4e, 0x53, 0x54, 0x65, /* RMMDNSTe */
0x73, 0x74, 0x05, 0x6c, 0x6f, 0x63, 0x61, 0x6c, /* st.local */
0x00, 0x00, 0xff, 0x00, 0x01, 0x0b, 0x41, 0x52, /* ......AR */
0x4d, 0x4d, 0x44, 0x4e, 0x53, 0x54, 0x65, 0x73, /* MMDNSTes */
0x74, 0x05, 0x5f, 0x68, 0x74, 0x74, 0x70, 0x04, /* t._http. */
0x5f, 0x74, 0x63, 0x70, 0x05, 0x6c, 0x6f, 0x63, /* _tcp.loc */
0x61, 0x6c, 0x00, 0x00, 0xff, 0x00, 0x01, 0x0b, /* al...... */
0x41, 0x52, 0x4d, 0x4d, 0x44, 0x4e, 0x53, 0x54, /* ARMMDNST */
0x65, 0x73, 0x74, 0x05, 0x6c, 0x6f, 0x63, 0x61, /* est.loca */
0x6c, 0x00, 0x00, 0x01, 0x80, 0x01, 0x00, 0x00, /* l....... */
0x00, 0x78, 0x00, 0x04, 0x0a, 0x00, 0x00, 0x42, /* .x.....B */
0x0b, 0x41, 0x52, 0x4d, 0x4d, 0x44, 0x4e, 0x53, /* .ARMMDNS */
0x54, 0x65, 0x73, 0x74, 0x05, 0x5f, 0x68, 0x74, /* Test._ht */
0x74, 0x70, 0x04, 0x5f, 0x74, 0x63, 0x70, 0x05, /* tp._tcp. */
0x6c, 0x6f, 0x63, 0x61, 0x6c, 0x00, 0x00, 0x21, /* local..! */
0x80, 0x01, 0x00, 0x00, 0x00, 0x64, 0x00, 0x19, /* .....d.. */
0x00, 0x00, 0x00, 0x00, 0x00, 0x50, 0x0b, 0x41, /* .....P.A */
0x52, 0x4d, 0x4d, 0x44, 0x4e, 0x53, 0x54, 0x65, /* RMMDNSTe */
0x73, 0x74, 0x05, 0x6c, 0x6f, 0x63, 0x61, 0x6c, /* st.local */
0x00, 0x0b, 0x41, 0x52, 0x4d, 0x4d, 0x44, 0x4e, /* ..ARMMDN */
0x53, 0x54, 0x65, 0x73, 0x74, 0x05, 0x5f, 0x68, /* STest._h */
0x74, 0x74, 0x70, 0x04, 0x5f, 0x74, 0x63, 0x70, /* ttp._tcp */
0x05, 0x6c, 0x6f, 0x63, 0x61, 0x6c, 0x00, 0x00, /* .local.. */
0x10, 0x80, 0x01, 0x00, 0x00, 0x00, 0x64, 0x00, /* ......d. */
0x14, 0x08, 0x70, 0x61, 0x70, 0x65, 0x72, 0x3d, /* ..paper= */
0x41, 0x34, 0x0a, 0x76, 0x65, 0x72, 0x73, 0x69, /* A4.versi */
0x6f, 0x6e, 0x3d, 0x30, 0x31                    /* on=01 */
};

/* Frame (269 bytes) */
static const unsigned char pkt2[269] = {
0x01, 0x00, 0x5e, 0x00, 0x00, 0xfb, 0x00, 0x11, /* ..^..... */
0x22, 0x33, 0x44, 0x57, 0x08, 0x00, 0x45, 0x00, /* "3DW..E. */
0x00, 0xff, 0x00, 0x02, 0x40, 0x00, 0xff, 0x11, /* ....@... */
0x8f, 0xae, 0x0a, 0x00, 0x00, 0x42, 0xe0, 0x00, /* .....B.. */
0x00, 0xfb, 0x14, 0xe9, 0x14, 0xe9, 0x00, 0xeb, /* ........ */
0x13, 0x25, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, /* .%...... */
0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x0b, 0x41, /* .......A */
0x52, 0x4d, 0x4d, 0x44, 0x4e, 0x53, 0x54, 0x65, /* RMMDNSTe */
0x73, 0x74, 0x05, 0x6c, 0x6f, 0x63, 0x61, 0x6c, /* st.local */
0x00, 0x00, 0xff, 0x00, 0x01, 0x0b, 0x41, 0x52, /* ......AR */
0x4d, 0x4d, 0x44, 0x4e, 0x53, 0x54, 0x65, 0x73, /* MMDNSTes */
0x74, 0x05, 0x5f, 0x68, 0x74, 0x74, 0x70, 0x04, /* t._http. */
0x5f, 0x74, 0x63, 0x70, 0x05, 0x6c, 0x6f, 0x63, /* _tcp.loc */
0x61, 0x6c, 0x00, 0x00, 0xff, 0x00, 0x01, 0x0b, /* al...... */
0x41, 0x52, 0x4d, 0x4d, 0x44, 0x4e, 0x53, 0x54, /* ARMMDNST */
0x65, 0x73, 0x74, 0x05, 0x6c, 0x6f, 0x63, 0x61, /* est.loca */
0x6c, 0x00, 0x00, 0x01, 0x80, 0x01, 0x00, 0x00, /* l....... */
0x00, 0x78, 0x00, 0x04, 0x0a, 0x00, 0x00, 0x42, /* .x.....B */
0x0b, 0x41, 0x52, 0x4d, 0x4d, 0x44, 0x4e, 0x53, /* .ARMMDNS */
0x54, 0x65, 0x73, 0x74, 0x05, 0x5f, 0x68, 0x74, /* Test._ht */
0x74, 0x70, 0x04, 0x5f, 0x74, 0x63, 0x70, 0x05, /* tp._tcp. */
0x6c, 0x6f, 0x63, 0x61, 0x6c, 0x00, 0x00, 0x21, /* local..! */
0x80, 0x01, 0x00, 0x00, 0x00, 0x64, 0x00, 0x19, /* .....d.. */
0x00, 0x00, 0x00, 0x00, 0x00, 0x50, 0x0b, 0x41, /* .....P.A */
0x52, 0x4d, 0x4d, 0x44, 0x4e, 0x53, 0x54, 0x65, /* RMMDNSTe */
0x73, 0x74, 0x05, 0x6c, 0x6f, 0x63, 0x61, 0x6c, /* st.local */
0x00, 0x0b, 0x41, 0x52, 0x4d, 0x4d, 0x44, 0x4e, /* ..ARMMDN */
0x53, 0x54, 0x65, 0x73, 0x74, 0x05, 0x5f, 0x68, /* STest._h */
0x74, 0x74, 0x70, 0x04, 0x5f, 0x74, 0x63, 0x70, /* ttp._tcp */
0x05, 0x6c, 0x6f, 0x63, 0x61, 0x6c, 0x00, 0x00, /* .local.. */
0x10, 0x80, 0x01, 0x00, 0x00, 0x00, 0x64, 0x00, /* ......d. */
0x14, 0x08, 0x70, 0x61, 0x70, 0x65, 0x72, 0x3d, /* ..paper= */
0x41, 0x34, 0x0a, 0x76, 0x65, 0x72, 0x73, 0x69, /* A4.versi */
0x6f, 0x6e, 0x3d, 0x30, 0x31                    /* on=01 */
};

/* Frame (269 bytes) */
static const unsigned char pkt3[269] = {
0x01, 0x00, 0x5e, 0x00, 0x00, 0xfb, 0x00, 0x11, /* ..^..... */
0x22, 0x33, 0x44, 0x57, 0x08, 0x00, 0x45, 0x00, /* "3DW..E. */
0x00, 0xff, 0x00, 0x03, 0x40, 0x00, 0xff, 0x11, /* ....@... */
0x8f, 0xad, 0x0a, 0x00, 0x00, 0x42, 0xe0, 0x00, /* .....B.. */
0x00, 0xfb, 0x14, 0xe9, 0x14, 0xe9, 0x00, 0xeb, /* ........ */
0x13, 0x25, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, /* .%...... */
0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x0b, 0x41, /* .......A */
0x52, 0x4d, 0x4d, 0x44, 0x4e, 0x53, 0x54, 0x65, /* RMMDNSTe */
0x73, 0x74, 0x05, 0x6c, 0x6f, 0x63, 0x61, 0x6c, /* st.local */
0x00, 0x00, 0xff, 0x00, 0x01, 0x0b, 0x41, 0x52, /* ......AR */
0x4d, 0x4d, 0x44, 0x4e, 0x53, 0x54, 0x65, 0x73, /* MMDNSTes */
0x74, 0x05, 0x5f, 0x68, 0x74, 0x74, 0x70, 0x04, /* t._http. */
0x5f, 0x74, 0x63, 0x70, 0x05, 0x6c, 0x6f, 0x63, /* _tcp.loc */
0x61, 0x6c, 0x00, 0x00, 0xff, 0x00, 0x01, 0x0b, /* al...... */
0x41, 0x52, 0x4d, 0x4d, 0x44, 0x4e, 0x53, 0x54, /* ARMMDNST */
0x65, 0x73, 0x74, 0x05, 0x6c, 0x6f, 0x63, 0x61, /* est.loca */
0x6c, 0x00, 0x00, 0x01, 0x80, 0x01, 0x00, 0x00, /* l....... */
0x00, 0x78, 0x00, 0x04, 0x0a, 0x00, 0x00, 0x42, /* .x.....B */
0x0b, 0x41, 0x52, 0x4d, 0x4d, 0x44, 0x4e, 0x53, /* .ARMMDNS */
0x54, 0x65, 0x73, 0x74, 0x05, 0x5f, 0x68, 0x74, /* Test._ht */
0x74, 0x70, 0x04, 0x5f, 0x74, 0x63, 0x70, 0x05, /* tp._tcp. */
0x6c, 0x6f, 0x63, 0x61, 0x6c, 0x00, 0x00, 0x21, /* local..! */
0x80, 0x01, 0x00, 0x00, 0x00, 0x64, 0x00, 0x19, /* .....d.. */
0x00, 0x00, 0x00, 0x00, 0x00, 0x50, 0x0b, 0x41, /* .....P.A */
0x52, 0x4d, 0x4d, 0x44, 0x4e, 0x53, 0x54, 0x65, /* RMMDNSTe */
0x73, 0x74, 0x05, 0x6c, 0x6f, 0x63, 0x61, 0x6c, /* st.local */
0x00, 0x0b, 0x41, 0x52, 0x4d, 0x4d, 0x44, 0x4e, /* ..ARMMDN */
0x53, 0x54, 0x65, 0x73, 0x74, 0x05, 0x5f, 0x68, /* STest._h */
0x74, 0x74, 0x70, 0x04, 0x5f, 0x74, 0x63, 0x70, /* ttp._tcp */
0x05, 0x6c, 0x6f, 0x63, 0x61, 0x6c, 0x00, 0x00, /* .local.. */
0x10, 0x80, 0x01, 0x00, 0x00, 0x00, 0x64, 0x00, /* ......d. */
0x14, 0x08, 0x70, 0x61, 0x70, 0x65, 0x72, 0x3d, /* ..paper= */
0x41, 0x34, 0x0a, 0x76, 0x65, 0x72, 0x73, 0x69, /* A4.versi */
0x6f, 0x6e, 0x3d, 0x30, 0x31                    /* on=01 */
};

/* Frame (398 bytes) */
static const unsigned char pkt4[398] = {
0x01, 0x00, 0x5e, 0x00, 0x00, 0xfb, 0x00, 0x11, /* ..^..... */
0x22, 0x33, 0x44, 0x57, 0x08, 0x00, 0x45, 0x00, /* "3DW..E. */
0x01, 0x80, 0x00, 0x04, 0x40, 0x00, 0xff, 0x11, /* ....@... */
0x8f, 0x2b, 0x0a, 0x00, 0x00, 0x42, 0xe0, 0x00, /* .+...B.. */
0x00, 0xfb, 0x14, 0xe9, 0x14, 0xe9, 0x01, 0x6c, /* .......l */
0x46, 0x47, 0x00, 0x00, 0x84, 0x00, 0x00, 0x00, /* FG...... */
0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x0b, 0x41, /* .......A */
0x52, 0x4d, 0x4d, 0x44, 0x4e, 0x53, 0x54, 0x65, /* RMMDNSTe */
0x73, 0x74, 0x05, 0x6c, 0x6f, 0x63, 0x61, 0x6c, /* st.local */
0x00, 0x00, 0x01, 0x80, 0x01, 0x00, 0x00, 0x00, /* ........ */
0x78, 0x00, 0x04, 0x0a, 0x00, 0x00, 0x42, 0x0b, /* x.....B. */
0x41, 0x52, 0x4d, 0x4d, 0x44, 0x4e, 0x53, 0x54, /* ARMMDNST */
0x65, 0x73, 0x74, 0x05, 0x6c, 0x6f, 0x63, 0x61, /* est.loca */
0x6c, 0x00, 0x00, 0x2f, 0x80, 0x01, 0x00, 0x00, /* l../.... */
0x00, 0x78, 0x00, 0x16, 0x0b, 0x41, 0x52, 0x4d, /* .x...ARM */
0x4d, 0x44, 0x4e, 0x53, 0x54, 0x65, 0x73, 0x74, /* MDNSTest */
0x05, 0x6c, 0x6f, 0x63, 0x61, 0x6c, 0x00, 0x00, /* .local.. */
0x01, 0x40, 0x0b, 0x41, 0x52, 0x4d, 0x4d, 0x44, /* .@.ARMMD */
0x4e, 0x53, 0x54, 0x65, 0x73, 0x74, 0x05, 0x5f, /* NSTest._ */
0x68, 0x74, 0x74, 0x70, 0x04, 0x5f, 0x74, 0x63, /* http._tc */
0x70, 0x05, 0x6c, 0x6f, 0x63, 0x61, 0x6c, 0x00, /* p.local. */
0x00, 0x21, 0x80, 0x01, 0x00, 0x00, 0x00, 0x64, /* .!.....d */
0x00, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x50, /* .......P */
0x0b, 0x41, 0x52, 0x4d, 0x4d, 0x44, 0x4e, 0x53, /* .ARMMDNS */
0x54, 0x65, 0x73, 0x74, 0x05, 0x6c, 0x6f, 0x63, /* Test.loc */
0x61, 0x6c, 0x00, 0x0b, 0x41, 0x52, 0x4d, 0x4d, /* al..ARMM */
0x44, 0x4e, 0x53, 0x54, 0x65, 0x73, 0x74, 0x05, /* DNSTest. */
0x5f, 0x68, 0x74, 0x74, 0x70, 0x04, 0x5f, 0x74, /* _http._t */
0x63, 0x70, 0x05, 0x6c, 0x6f, 0x63, 0x61, 0x6c, /* cp.local */
0x00, 0x00, 0x10, 0x80, 0x01, 0x00, 0x00, 0x00, /* ........ */
0x64, 0x00, 0x14, 0x08, 0x70, 0x61, 0x70, 0x65, /* d...pape */
0x72, 0x3d, 0x41, 0x34, 0x0a, 0x76, 0x65, 0x72, /* r=A4.ver */
0x73, 0x69, 0x6f, 0x6e, 0x3d, 0x30, 0x31, 0x05, /* sion=01. */
0x5f, 0x68, 0x74, 0x74, 0x70, 0x04, 0x5f, 0x74, /* _http._t */
0x63, 0x70, 0x05, 0x6c, 0x6f, 0x63, 0x61, 0x6c, /* cp.local */
0x00, 0x00, 0x0c, 0x00, 0x01, 0x00, 0x00, 0x00, /* ........ */
0x64, 0x00, 0x1e, 0x0b, 0x41, 0x52, 0x4d, 0x4d, /* d...ARMM */
0x44, 0x4e, 0x53, 0x54, 0x65, 0x73, 0x74, 0x05, /* DNSTest. */
0x5f, 0x68, 0x74, 0x74, 0x70, 0x04, 0x5f, 0x74, /* _http._t */
0x63, 0x70, 0x05, 0x6c, 0x6f, 0x63, 0x61, 0x6c, /* cp.local */
0x00, 0x0b, 0x41, 0x52, 0x4d, 0x4d, 0x44, 0x4e, /* ..ARMMDN */
0x53, 0x54, 0x65, 0x73, 0x74, 0x05, 0x5f, 0x68, /* STest._h */
0x74, 0x74, 0x70, 0x04, 0x5f, 0x74, 0x63, 0x70, /* ttp._tcp */
0x05, 0x6c, 0x6f, 0x63, 0x61, 0x6c, 0x00, 0x00, /* .local.. */
0x2f, 0x80, 0x01, 0x00, 0x00, 0x00, 0x78, 0x00, /* /.....x. */
0x25, 0x0b, 0x41, 0x52, 0x4d, 0x4d, 0x44, 0x4e, /* %.ARMMDN */
0x53, 0x54, 0x65, 0x73, 0x74, 0x05, 0x5f, 0x68, /* STest._h */
0x74, 0x74, 0x70, 0x04, 0x5f, 0x74, 0x63, 0x70, /* ttp._tcp */
0x05, 0x6c, 0x6f, 0x63, 0x61, 0x6c, 0x00, 0x00, /* .local.. */
0x05, 0x00, 0x00, 0x80, 0x00, 0x40              /* .....@ */
};

/* Frame (398 bytes) */
static const unsigned char pkt5[398] = {
0x01, 0x00, 0x5e, 0x00, 0x00, 0xfb, 0x00, 0x11, /* ..^..... */
0x22, 0x33, 0x44, 0x57, 0x08, 0x00, 0x45, 0x00, /* "3DW..E. */
0x01, 0x80, 0x00, 0x05, 0x40, 0x00, 0xff, 0x11, /* ....@... */
0x8f, 0x2a, 0x0a, 0x00, 0x00, 0x42, 0xe0, 0x00, /* .*...B.. */
0x00, 0xfb, 0x14, 0xe9, 0x14, 0xe9, 0x01, 0x6c, /* .......l */
0x46, 0x47, 0x00, 0x00, 0x84, 0x00, 0x00, 0x00, /* FG...... */
0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x0b, 0x41, /* .......A */
0x52, 0x4d, 0x4d, 0x44, 0x4e, 0x53, 0x54, 0x65, /* RMMDNSTe */
0x73, 0x74, 0x05, 0x6c, 0x6f, 0x63, 0x61, 0x6c, /* st.local */
0x00, 0x00, 0x01, 0x80, 0x01, 0x00, 0x00, 0x00, /* ........ */
0x78, 0x00, 0x04, 0x0a, 0x00, 0x00, 0x42, 0x0b, /* x.....B. */
0x41, 0x52, 0x4d, 0x4d, 0x44, 0x4e, 0x53, 0x54, /* ARMMDNST */
0x65, 0x73, 0x74, 0x05, 0x6c, 0x6f, 0x63, 0x61, /* est.loca */
0x6c, 0x00, 0x00, 0x2f, 0x80, 0x01, 0x00, 0x00, /* l../.... */
0x00, 0x78, 0x00, 0x16, 0x0b, 0x41, 0x52, 0x4d, /* .x...ARM */
0x4d, 0x44, 0x4e, 0x53, 0x54, 0x65, 0x73, 0x74, /* MDNSTest */
0x05, 0x6c, 0x6f, 0x63, 0x61, 0x6c, 0x00, 0x00, /* .local.. */
0x01, 0x40, 0x0b, 0x41, 0x52, 0x4d, 0x4d, 0x44, /* .@.ARMMD */
0x4e, 0x53, 0x54, 0x65, 0x73, 0x74, 0x05, 0x5f, /* NSTest._ */
0x68, 0x74, 0x74, 0x70, 0x04, 0x5f, 0x74, 0x63, /* http._tc */
0x70, 0x05, 0x6c, 0x6f, 0x63, 0x61, 0x6c, 0x00, /* p.local. */
0x00, 0x21, 0x80, 0x01, 0x00, 0x00, 0x00, 0x64, /* .!.....d */
0x00, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x50, /* .......P */
0x0b, 0x41, 0x52, 0x4d, 0x4d, 0x44, 0x4e, 0x53, /* .ARMMDNS */
0x54, 0x65, 0x73, 0x74, 0x05, 0x6c, 0x6f, 0x63, /* Test.loc */
0x61, 0x6c, 0x00, 0x0b, 0x41, 0x52, 0x4d, 0x4d, /* al..ARMM */
0x44, 0x4e, 0x53, 0x54, 0x65, 0x73, 0x74, 0x05, /* DNSTest. */
0x5f, 0x68, 0x74, 0x74, 0x70, 0x04, 0x5f, 0x74, /* _http._t */
0x63, 0x70, 0x05, 0x6c, 0x6f, 0x63, 0x61, 0x6c, /* cp.local */
0x00, 0x00, 0x10, 0x80, 0x01, 0x00, 0x00, 0x00, /* ........ */
0x64, 0x00, 0x14, 0x08, 0x70, 0x61, 0x70, 0x65, /* d...pape */
0x72, 0x3d, 0x41, 0x34, 0x0a, 0x76, 0x65, 0x72, /* r=A4.ver */
0x73, 0x69, 0x6f, 0x6e, 0x3d, 0x30, 0x31, 0x05, /* sion=01. */
0x5f, 0x68, 0x74, 0x74, 0x70, 0x04, 0x5f, 0x74, /* _http._t */
0x63, 0x70, 0x05, 0x6c, 0x6f, 0x63, 0x61, 0x6c, /* cp.local */
0x00, 0x00, 0x0c, 0x00, 0x01, 0x00, 0x00, 0x00, /* ........ */
0x64, 0x00, 0x1e, 0x0b, 0x41, 0x52, 0x4d, 0x4d, /* d...ARMM */
0x44, 0x4e, 0x53, 0x54, 0x65, 0x73, 0x74, 0x05, /* DNSTest. */
0x5f, 0x68, 0x74, 0x74, 0x70, 0x04, 0x5f, 0x74, /* _http._t */
0x63, 0x70, 0x05, 0x6c, 0x6f, 0x63, 0x61, 0x6c, /* cp.local */
0x00, 0x0b, 0x41, 0x52, 0x4d, 0x4d, 0x44, 0x4e, /* ..ARMMDN */
0x53, 0x54, 0x65, 0x73, 0x74, 0x05, 0x5f, 0x68, /* STest._h */
0x74, 0x74, 0x70, 0x04, 0x5f, 0x74, 0x63, 0x70, /* ttp._tcp */
0x05, 0x6c, 0x6f, 0x63, 0x61, 0x6c, 0x00, 0x00, /* .local.. */
0x2f, 0x80, 0x01, 0x00, 0x00, 0x00, 0x78, 0x00, /* /.....x. */
0x25, 0x0b, 0x41, 0x52, 0x4d, 0x4d, 0x44, 0x4e, /* %.ARMMDN */
0x53, 0x54, 0x65, 0x73, 0x74, 0x05, 0x5f, 0x68, /* STest._h */
0x74, 0x74, 0x70, 0x04, 0x5f, 0x74, 0x63, 0x70, /* ttp._tcp */
0x05, 0x6c, 0x6f, 0x63, 0x61, 0x6c, 0x00, 0x00, /* .local.. */
0x05, 0x00, 0x00, 0x80, 0x00, 0x40              /* .....@ */
};

/* Frame (398 bytes) */
static const unsigned char pkt6[398] = {
0x01, 0x00, 0x5e, 0x00, 0x00, 0xfb, 0x00, 0x11, /* ..^..... */
0x22, 0x33, 0x44, 0x57, 0x08, 0x00, 0x45, 0x00, /* "3DW..E. */
0x01, 0x80, 0x00, 0x06, 0x40, 0x00, 0xff, 0x11, /* ....@... */
0x8f, 0x29, 0x0a, 0x00, 0x00, 0x42, 0xe0, 0x00, /* .)...B.. */
0x00, 0xfb, 0x14, 0xe9, 0x14, 0xe9, 0x01, 0x6c, /* .......l */
0x46, 0x47, 0x00, 0x00, 0x84, 0x00, 0x00, 0x00, /* FG...... */
0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x0b, 0x41, /* .......A */
0x52, 0x4d, 0x4d, 0x44, 0x4e, 0x53, 0x54, 0x65, /* RMMDNSTe */
0x73, 0x74, 0x05, 0x6c, 0x6f, 0x63, 0x61, 0x6c, /* st.local */
0x00, 0x00, 0x01, 0x80, 0x01, 0x00, 0x00, 0x00, /* ........ */
0x78, 0x00, 0x04, 0x0a, 0x00, 0x00, 0x42, 0x0b, /* x.....B. */
0x41, 0x52, 0x4d, 0x4d, 0x44, 0x4e, 0x53, 0x54, /* ARMMDNST */
0x65, 0x73, 0x74, 0x05, 0x6c, 0x6f, 0x63, 0x61, /* est.loca */
0x6c, 0x00, 0x00, 0x2f, 0x80, 0x01, 0x00, 0x00, /* l../.... */
0x00, 0x78, 0x00, 0x16, 0x0b, 0x41, 0x52, 0x4d, /* .x...ARM */
0x4d, 0x44, 0x4e, 0x53, 0x54, 0x65, 0x73, 0x74, /* MDNSTest */
0x05, 0x6c, 0x6f, 0x63, 0x61, 0x6c, 0x00, 0x00, /* .local.. */
0x01, 0x40, 0x0b, 0x41, 0x52, 0x4d, 0x4d, 0x44, /* .@.ARMMD */
0x4e, 0x53, 0x54, 0x65, 0x73, 0x74, 0x05, 0x5f, /* NSTest._ */
0x68, 0x74, 0x74, 0x70, 0x04, 0x5f, 0x74, 0x63, /* http._tc */
0x70, 0x05, 0x6c, 0x6f, 0x63, 0x61, 0x6c, 0x00, /* p.local. */
0x00, 0x21, 0x80, 0x01, 0x00, 0x00, 0x00, 0x64, /* .!.....d */
0x00, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x50, /* .......P */
0x0b, 0x41, 0x52, 0x4d, 0x4d, 0x44, 0x4e, 0x53, /* .ARMMDNS */
0x54, 0x65, 0x73, 0x74, 0x05, 0x6c, 0x6f, 0x63, /* Test.loc */
0x61, 0x6c, 0x00, 0x0b, 0x41, 0x52, 0x4d, 0x4d, /* al..ARMM */
0x44, 0x4e, 0x53, 0x54, 0x65, 0x73, 0x74, 0x05, /* DNSTest. */
0x5f, 0x68, 0x74, 0x74, 0x70, 0x04, 0x5f, 0x74, /* _http._t */
0x63, 0x70, 0x05, 0x6c, 0x6f, 0x63, 0x61, 0x6c, /* cp.local */
0x00, 0x00, 0x10, 0x80, 0x01, 0x00, 0x00, 0x00, /* ........ */
0x64, 0x00, 0x14, 0x08, 0x70, 0x61, 0x70, 0x65, /* d...pape */
0x72, 0x3d, 0x41, 0x34, 0x0a, 0x76, 0x65, 0x72, /* r=A4.ver */
0x73, 0x69, 0x6f, 0x6e, 0x3d, 0x30, 0x31, 0x05, /* sion=01. */
0x5f, 0x68, 0x74, 0x74, 0x70, 0x04, 0x5f, 0x74, /* _http._t */
0x63, 0x70, 0x05, 0x6c, 0x6f, 0x63, 0x61, 0x6c, /* cp.local */
0x00, 0x00, 0x0c, 0x00, 0x01, 0x00, 0x00, 0x00, /* ........ */
0x64, 0x00, 0x1e, 0x0b, 0x41, 0x52, 0x4d, 0x4d, /* d...ARMM */
0x44, 0x4e, 0x53, 0x54, 0x65, 0x73, 0x74, 0x05, /* DNSTest. */
0x5f, 0x68, 0x74, 0x74, 0x70, 0x04, 0x5f, 0x74, /* _http._t */
0x63, 0x70, 0x05, 0x6c, 0x6f, 0x63, 0x61, 0x6c, /* cp.local */
0x00, 0x0b, 0x41, 0x52, 0x4d, 0x4d, 0x44, 0x4e, /* ..ARMMDN */
0x53, 0x54, 0x65, 0x73, 0x74, 0x05, 0x5f, 0x68, /* STest._h */
0x74, 0x74, 0x70, 0x04, 0x5f, 0x74, 0x63, 0x70, /* ttp._tcp */
0x05, 0x6c, 0x6f, 0x63, 0x61, 0x6c, 0x00, 0x00, /* .local.. */
0x2f, 0x80, 0x01, 0x00, 0x00, 0x00, 0x78, 0x00, /* /.....x. */
0x25, 0x0b, 0x41, 0x52, 0x4d, 0x4d, 0x44, 0x4e, /* %.ARMMDN */
0x53, 0x54, 0x65, 0x73, 0x74, 0x05, 0x5f, 0x68, /* STest._h */
0x74, 0x74, 0x70, 0x04, 0x5f, 0x74, 0x63, 0x70, /* ttp._tcp */
0x05, 0x6c, 0x6f, 0x63, 0x61, 0x6c, 0x00, 0x00, /* .local.. */
0x05, 0x00, 0x00, 0x80, 0x00, 0x40              /* .....@ */
};

static MDNS_SERVICE mdns_service = {"ARMMDNSTest", "_http._tcp", NX_NULL, "paper=A4;version=01", 100, 0, 0, 80, NX_MDNS_RR_SET_UNIQUE, 0};

#define resonable_error 5

MDNS_TEST_SEQ mdns_server_announcement_with_txt[] = {
    {TITLE, "Server announcement with TXT", 28, 0},
    {MDNS_TIMER_RESET, NX_NULL, 0, 0},

    {MDNS_SERVICE_ADD, (char*)&mdns_service, 0, 0},

    /* The first probing. Interval between 0~260ms. */
    {MDNS_CHECK_DATA_V4, (char*)&pkt1[0], sizeof(pkt1), 1},
    {MDNS_TIMER_CHECK, NX_NULL, 13 + resonable_error, 13 + resonable_error},
    {MDNS_TIMER_RESET, NX_NULL, 0, 0},

    /* The second probing. Interval between 0~260ms. */
    {MDNS_CHECK_DATA_V4, (char*)&pkt2[0], sizeof(pkt2), 1},
    {MDNS_TIMER_CHECK, NX_NULL, 13 + resonable_error, 13 + resonable_error},
    {MDNS_TIMER_RESET, NX_NULL, 0, 0},

    /* The third probing. Interval between 0~260ms. */
    {MDNS_CHECK_DATA_V4, (char*)&pkt3[0], sizeof(pkt3), 1},
    {MDNS_TIMER_CHECK, NX_NULL, 13 + resonable_error, 13 + resonable_error},
    {MDNS_TIMER_RESET, NX_NULL, 0, 0},

    /* Check announcement. Interval between 0~260ms. */
    {MDNS_CHECK_DATA_V4, (char*)&pkt4[0], sizeof(pkt4), 1},
    {MDNS_TIMER_CHECK, NX_NULL, 13 + resonable_error, 13 + resonable_error},
    {MDNS_TIMER_RESET, NX_NULL, 0, 0},
    
    /* Check announcement. Interval 1s. */
    {MDNS_CHECK_DATA_V4, (char*)&pkt5[0], sizeof(pkt5), 1},
    {MDNS_TIMER_CHECK, NX_NULL, 3 + resonable_error, 100},
    {MDNS_TIMER_RESET, NX_NULL, 0, 0},
        
    /* Check announcement. Interval 2s. */
    {MDNS_CHECK_DATA_V4, (char*)&pkt6[0], sizeof(pkt6), 2},
    {MDNS_TIMER_CHECK, NX_NULL, 3 + resonable_error, 200},
    {MDNS_TIMER_RESET, NX_NULL, 0, 0},
};

int mdns_server_announcement_with_txt_size = sizeof(mdns_server_announcement_with_txt) / sizeof(MDNS_TEST_SEQ);

#endif /* __PRODUCT_NETXDUO__  */
