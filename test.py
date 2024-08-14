class URLParser:
    def __init__(self, url) -> None:
        self.url = url
        self.componentsCache = {}

    def getScheme(self):
        if self.componentsCache.get("scheme", None): 
            return self.componentsCache["scheme"]
        
        components = self.url.split(":")

        self.componentsCache["scheme"] = components[0]
        return components[0]
    
    def getAuthority(self):
        components = self.url.split("/")
        return components[2]

    def getPath(self):
        componentsAfterQsmSplit = self.url.split("?")

        componentsAfterSlashSplit= componentsAfterQsmSplit[0].split("/")
        
        # print(componentsAfterSlashSplit)
        authorityIndex = 0
        authorityComponent = self.getAuthority()
        for index, component in enumerate(componentsAfterSlashSplit):
            if component == authorityComponent: 
                authorityIndex = index
                break
        
        path = '/'
        for index in range(authorityIndex + 1, len(componentsAfterSlashSplit)):
            path += componentsAfterSlashSplit[index]
            if index != len(componentsAfterSlashSplit) - 1:
                path += '/'
        return path
    def getParams(self):
        componentsAfterQsmSplit = self.url.split("?")
        if len(componentsAfterQsmSplit) != 2 or not componentsAfterQsmSplit[1]: return {}
        paramsComponent = componentsAfterQsmSplit[1].split("#")[0]

        kvPairs = paramsComponent.split("&")

        map = {}

        for kvPair in kvPairs:
            if not kvPair: continue
            key, value = kvPair.split("=")
            # if ket dosn have value yet, init by an empty list then append the new value into the list
            map[key] = value

        return map 
    
    def getAnchor(self):
        components = self.url.split("#")
        # print(components)
        if len(components) != 2 or not components[1]: return ''
        return components[1]
    
    def reconstructParams(self, map):
        paramsComponent = '?'

        for key, value in map.items():
            paramStr = key + '=' + value + '&' 
            paramsComponent += paramStr
        # Remove last character 
        paramsComponent = paramsComponent[:-1]
        return paramsComponent

    def reconstructUrl(self):
        scheme = self.getScheme()
        authority = self.getAuthority()
        path = self.getPath()
        paramsMap = self.getParams()
        anchor = self.getAnchor()

        reconstructedUrl = ''
        
        # Construct scheme
        reconstructedUrl += scheme + '://'
        # Construct authority
        reconstructedUrl += authority
        # Construct path
        reconstructedUrl += path
        # Construct params
        reconstructedUrl += self.reconstructParams(paramsMap)
        # Construct anchor
        if anchor: reconstructedUrl += '#' + anchor

        return reconstructedUrl

    def printUrl(self):
        print(self.url)


print("Url parser 1:")
urlParser = URLParser("https://www.example.com/path/to/resource")
# print(urlParser.getScheme())
# print(urlParser.getScheme())
# print(urlParser.getAuthority())
# print(urlParser.getPath())
# print(urlParser.getParams())
# print(urlParser.getAnchor())
print(urlParser.reconstructUrl())
print(urlParser.printUrl())

# print("Url Parser 2:\n")
# urlParser2 = URLParser("https://www.example.com/path/to/resource?key1=value1&key2=value2#")
# print(urlParser2.getPath())
# print(urlParser2.getParams())
# print(urlParser2.getAnchor())
# print(urlParser2.reconstructUrl())
# print(urlParser2.printUrl())


# print("Url Parser 3:\n")
# urlParser2 = URLParser("https://www.example.com/path/to/resource?")
# print(urlParser2.getPath())
# print(urlParser2.getParams())