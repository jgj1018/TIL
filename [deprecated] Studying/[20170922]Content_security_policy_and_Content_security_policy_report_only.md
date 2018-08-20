
# Content Security Policy

CSP is an added layer of security that helps to detect and mitigate certain types of attacks(XSS, data injection) Thses attacks are used for everything from data theft to site defacement or distribution of malware.

To enable CSP, I need to configure my web server to return the `Content-Security-Policy` HTTP header. or I can use `<meta> element`.

A primary goal of CSP is to mitigate and report XSS attacks. CSP makes it possible for server administrators to reduce or eliminate the vectors by which XSS can occur by specifying the domains that the browser should consider to be valid sources of executable scripts.

Example
 
(1) all content to come from the site's own origin
```
Content-Security-Policy: default-src 'self'
```

(2) content from a trusted domain and all its subdomains.
```
Content-Security-Policy: default-src 'self' *.truted.com
```

(3) onlinebanking.com want to ensure that all its content is loaded using SSL
```
Content-Security-Policy: default-src https://onlinebanking.com
```


# Content Security Policy Report Only

To ease deployment, CSP can be deployed in report-only mode. The policy is not enforced, but any violations are reported to a provided URI. 

```
Content-Security-Policy-Report-Only: policy 
``` 

- Enabling reporting

By default, violation reports aren't sent. To enable violation reporting, I need to specify the `report-uri` policy directive, providing at least one URI to which to deliver the reports.

```
Content-Security-Policy: default-src 'self'; report-uri http://reportcollector.example.com/collector.cgi
```


[reference1:Content Security Policy](https://developer.mozilla.org/en-US/docs/Web/HTTP/CSP)

[reference2:Content Security Policy Report Only](https://developer.mozilla.org/en-US/docs/Web/HTTP/Headers/Content-Security-Policy-Report-Only)